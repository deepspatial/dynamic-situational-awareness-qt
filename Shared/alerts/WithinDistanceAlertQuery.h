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

#ifndef WITHONDISTANCEALERTQUERY_H
#define WITHONDISTANCEALERTQUERY_H

#include "AlertQuery.h"

class AlertConditionData;

class WithinDistanceAlertQuery : public AlertQuery
{
  Q_OBJECT

public:
  explicit WithinDistanceAlertQuery(QObject* parent = nullptr);
  ~WithinDistanceAlertQuery();

  bool matchesRule(AlertConditionData* alert) const override;
};

#endif // WITHONDISTANCEALERTQUERY_H