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

#include "AlertCondition.h"
#include "AlertConditionData.h"
#include "AlertSource.h"
#include "AlertTarget.h"

using namespace Esri::ArcGISRuntime;

AlertConditionData::AlertConditionData(AlertCondition* condition, AlertSource* source, AlertTarget* target):
  QObject(condition),
  m_condition(condition),
  m_source(source),
  m_target(target)
{
  connect(m_condition, &AlertCondition::noLongerValid, this, &AlertConditionData::noLongerValid);
  connect(m_source, &AlertSource::noLongerValid, this, &AlertConditionData::noLongerValid);
  connect(m_source, &AlertSource::locationChanged, this, &AlertConditionData::locationChanged);
  connect(m_source, &AlertSource::destroyed, this, [this]()
  {
    m_source = nullptr;
    emit noLongerValid();
  });
  connect(m_target, &AlertTarget::locationChanged, this, &AlertConditionData::locationChanged);
  connect(m_target, &AlertTarget::destroyed, this, [this]()
  {
    m_target = nullptr;
    emit noLongerValid();
  });
}

AlertConditionData::~AlertConditionData()
{
  emit noLongerValid();
}

AlertLevel AlertConditionData::level() const
{
  return m_condition->level();
}

Point AlertConditionData::sourceLocation() const
{
  return m_source->location();
}

void AlertConditionData::highlight(bool on)
{
  source()->setSelected(on);
}

QString AlertConditionData::name() const
{
  return m_condition->name();
}

QUuid AlertConditionData::id() const
{
  return m_id;
}

void AlertConditionData::setId(const QUuid& id)
{
  m_id = id;
}

bool AlertConditionData::viewed() const
{
  return m_viewed;
}

void AlertConditionData::setViewed(bool viewed)
{
  if (viewed == m_viewed)
    return;

  m_viewed = viewed;
  emit viewedChanged();
}

void AlertConditionData::setActive(bool active)
{
  if (active == m_active)
    return;

  m_active = active;
  emit activeChanged();
}

AlertSource *AlertConditionData::source() const
{
  return m_source;
}

AlertTarget* AlertConditionData::target() const
{
  return m_target;
}

bool AlertConditionData::active() const
{
  return m_active;
}