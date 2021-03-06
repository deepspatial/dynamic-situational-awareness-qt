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

#ifndef ALERTLISTCONTROLLER_H
#define ALERTLISTCONTROLLER_H

// toolkit headers
#include "AbstractTool.h"

// Qt headers
#include <QAbstractListModel>

namespace Esri {
namespace ArcGISRuntime
{
  class GraphicsOverlay;
  class SimpleMarkerSceneSymbol;
}}

namespace Dsa {

class PointHighlighter;

class AlertFilter;
class AlertListProxyModel;
class IdsAlertFilter;
class StatusAlertFilter;

class AlertListController : public Esri::ArcGISRuntime::Toolkit::AbstractTool
{
  Q_OBJECT

  Q_PROPERTY(QAbstractItemModel* alertListModel READ alertListModel NOTIFY alertListModelChanged)
  Q_PROPERTY(int allAlertsCount READ allAlertsCount NOTIFY allAlertsCountChanged)

public:
  explicit AlertListController(QObject* parent = nullptr);
  ~AlertListController();

  QAbstractItemModel* alertListModel() const;
  int allAlertsCount() const;

  // AbstractTool interface
  QString toolName() const override;

  Q_INVOKABLE void highlight(int rowIndex, bool showHighlight);
  Q_INVOKABLE void zoomTo(int rowIndex);
  Q_INVOKABLE void setViewed(int rowIndex);
  Q_INVOKABLE void dismiss(int rowIndex);
  Q_INVOKABLE void setMinLevel(int level);
  Q_INVOKABLE void clearAllFilters();

  Q_INVOKABLE void flashAll(bool highlight);

signals:
  void alertListModelChanged();
  void allAlertsCountChanged();
  void highlightStopped();

private:
  AlertListProxyModel* m_alertsProxyModel = nullptr;
  StatusAlertFilter* m_statusAlertFilter = nullptr;
  IdsAlertFilter* m_idsAlertFilter = nullptr;
  QList<AlertFilter*> m_filters;
  PointHighlighter* m_highlighter = nullptr;

  QList<QMetaObject::Connection> m_highlightConnections;
};

} // Dsa

#endif // ALERTLISTCONTROLLER_H
