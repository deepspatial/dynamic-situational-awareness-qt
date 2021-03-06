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

// PCH header
#include "pch.hpp"

#include "WithinAreaAlertCondition.h"

// example app headers
#include "GraphicAlertSource.h"
#include "WithinAreaAlertConditionData.h"

// C++ API headers
#include "GraphicListModel.h"
#include "GraphicsOverlay.h"

using namespace Esri::ArcGISRuntime;

namespace Dsa {

/*!
  \class Dsa::WithinAreaAlertCondition
  \inmodule Dsa
  \inherits AlertCondition
  \brief Represents a spatial, "Geofence", condition which will be coninuosly monitored and will
  trigger an alert when a source object is within the area of a target object.

  This condition will create new \l WithinAreaAlertConditionData to track source and target objects.

  It can be tested using a \l WithinAreaAlertQuery.
  */

/*!
  \brief Constructor taking an \l AlertLevel (\a level) the \a name of the condition and
  an optional \a parent.
 */
WithinAreaAlertCondition::WithinAreaAlertCondition(AlertLevel level,
                                                   const QString& name,
                                                   QObject* parent):
  AlertCondition(level, name, parent)
{

}

/*!
  \brief Destructor.
 */
WithinAreaAlertCondition::~WithinAreaAlertCondition()
{

}

/*!
  \brief Creates a new \l WithinAreaAlertConditionData to track \a source and \a target objects.
 */
AlertConditionData* WithinAreaAlertCondition::createData(AlertSource* source, AlertTarget* target)
{
  return new WithinAreaAlertConditionData(newConditionDataName(), level(), source, target, this);
}

/*!
  \brief Returns the query string component for this condition - e.g. "is within".
 */
QString WithinAreaAlertCondition::queryString() const
{
  return isWithinQueryString();
}

/*!
  \brief Returns a map of the variable components that make up the query for this condition.

  \note This query type has no variable components.
 */
QVariantMap WithinAreaAlertCondition::queryComponents() const
{
  return QVariantMap();
}

/*!
  \brief Static method to get the query string "is within".
 */
QString WithinAreaAlertCondition::isWithinQueryString()
{
  return QStringLiteral("is within");
}


} // Dsa
