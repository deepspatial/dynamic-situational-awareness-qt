
// Copyright 2017 ESRI
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

Menu {
    id: contextMenu
    visible: contextMenuController.contextActive
    x: contextMenuController.contextScreenPosition.x
    y: contextMenuController.contextScreenPosition.y
    width: 110 * scaleFactor

    ContextMenuController {
        id: contextMenuController

        onResultChanged: {
            msgDialog.title = contextMenuController.resultTitle;
            msgDialog.informativeText = contextMenuController.result;
            msgDialog.open();
        }
    }

    onVisibleChanged: {
        if (!visible)
            contextMenuController.contextActive = visible;
    }

    Repeater {
        id: optionsRepeater
        model: contextMenuController.options
        anchors.margins: 8 * scaleFactor

        delegate: ListLabel{
            anchors{
                left: parent.left
                margins: 4 * scaleFactor
            }
            text: display
            horizontalAlignment: Text.AlignLeft

            onTriggered: {
                contextMenuController.selectOption(display);
            }
        }
    }
}
