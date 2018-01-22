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

#include "AbstractAlert.h"

using namespace Esri::ArcGISRuntime;

AbstractAlert::AbstractAlert(QObject* parent):
  QObject(parent)
{
}

AbstractAlert::~AbstractAlert()
{

}

AlertStatus AbstractAlert::status() const
{
  return m_status;
}

void AbstractAlert::setStatus(const AlertStatus& status)
{
  if (status == m_status)
    return;

  m_status = status;
  emit statusChanged();
}

QString AbstractAlert::message() const
{
  return m_message;
}

void AbstractAlert::setMessage(const QString& message)
{
  m_message = message;
}

QUuid AbstractAlert::id() const
{
  return m_id;
}

void AbstractAlert::setId(const QUuid& id)
{
  m_id = id;
}

bool AbstractAlert::viewed() const
{
  return m_viewed;
}

void AbstractAlert::setViewed(bool viewed)
{
  if (viewed == m_viewed)
    return;

  m_viewed = viewed;
  emit viewedChanged();
}

void AbstractAlert::onPositionChanged()
{
  emit positionChanged();
}

void AbstractAlert::setActive(bool active)
{
  if (active == m_active)
    return;

  m_active = active;
  emit activeChanged();
}

bool AbstractAlert::active() const
{
  return m_active;
}
