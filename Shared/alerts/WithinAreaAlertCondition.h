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

#ifndef WITHINAREAALERTCONDITION_H
#define WITHINAREAALERTCONDITION_H

// example app headers
#include "AlertCondition.h"

// Qt headers
#include <QObject>

namespace Dsa {

class WithinAreaAlertCondition : public AlertCondition
{
  Q_OBJECT

public:
  WithinAreaAlertCondition(AlertLevel level,
                           const QString& name,
                           QObject* parent = nullptr);

  ~WithinAreaAlertCondition();

  AlertConditionData* createData(AlertSource* source, AlertTarget* target) override;

  QString queryString() const override;
  QVariantMap queryComponents() const override;

  static QString isWithinQueryString();
};

} // Dsa

#endif // WITHINAREAALERTCONDITION_H
