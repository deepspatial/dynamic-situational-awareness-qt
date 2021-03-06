// Copyright 2018 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.2
import Esri.DSA 1.0
import Esri.ArcGISRuntime.Toolkit.Controls.CppApi 100.2

Row {
    id: alertToolRow
    spacing: 10 * scaleFactor
    visible: categoryToolbar.state === "alerts"
    property real scaleFactor: (Screen.logicalPixelDensity * 25.4) / (Qt.platform.os === "windows" ? 96 : 72)

    onVisibleChanged: {
        if (visible) {
            viewAlertIcon.selected = true;
            alertToolRow.state = viewAlertIcon.toolName;
            alertsTool.visible = true;
        } else {
            state = "clear";
        }
    }

    states: [
        State {
            name: viewAlertIcon.toolName
            PropertyChanges {
                target: viewAlertIcon
                selected: true
            }
        },
        State {
            name: createAlertIcon.toolName
            PropertyChanges {
                target: createAlertIcon
                selected: true
            }
        },
        State {
            name: "clear"
            PropertyChanges {
                target: viewAlertIcon
                selected: false
            }
            PropertyChanges {
                target: createAlertIcon
                selected: false
            }
            PropertyChanges {
                target: alertConditionsTool
                visible: false
            }
            PropertyChanges {
                target: alertsTool
                visible: false
            }
        }
    ]

    // View Alert Tool
    ToolIcon {
        id: viewAlertIcon
        iconSource: DsaResources.iconAlertList
        toolName: "View"
        onToolSelected: {
            alertConditionsTool.visible = false;
            if (alertToolRow.state === toolName) {
                alertToolRow.state = "clear";
                alertsTool.visible = false;
            } else {
                alertToolRow.state = toolName;
                alertsTool.visible = true;
            }
        }
    }

    // Create Alert Tool
    ToolIcon {
        id: createAlertIcon
        iconSource: DsaResources.iconAlertConditionList
        toolName: "Conditions"
        onToolSelected: {
            alertsTool.visible = false;
            if (alertToolRow.state === toolName) {
                alertToolRow.state = "clear";
                alertConditionsTool.visible = false;
            } else {
                alertToolRow.state = toolName;
                alertConditionsTool.visible = true;
            }
        }
    }
}
