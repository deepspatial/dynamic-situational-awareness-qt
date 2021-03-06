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

#include "AlertTarget.h"

namespace Dsa {

/*!
  \class Dsa::AlertTarget
  \inmodule Dsa
  \inherits QObject
  \brief Represents a target (e.g. an overlay or a real-time feed) for an \l AlertCondition.

  \note This is an abstract base type.
  */

/*!
  \brief Constructor taking an optional \a parent.
 */
AlertTarget::AlertTarget(QObject* parent):
  QObject(parent)
{

}

/*!
  \brief Destructor.
 */
AlertTarget::~AlertTarget()
{
  emit noLongerValid();
}

} // Dsa

// Signal Documentation
/*!
  \fn void AlertTarget::noLongerValid();
  \brief Signal emitted when alert target is no longer valid.
 */

/*!
  \fn void AlertTarget::dataChanged();
  \brief Signal emitted when alert target's data changes.
 */

