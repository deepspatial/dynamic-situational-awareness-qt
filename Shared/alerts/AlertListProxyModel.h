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

#ifndef ALERTLISTPROXYMODEL_H
#define ALERTLISTPROXYMODEL_H

// Qt headers
#include <QHash>
#include <QList>
#include <QSortFilterProxyModel>

namespace Dsa {

class AlertFilter;
class AlertListModel;

class AlertListProxyModel : public QSortFilterProxyModel
{
  Q_OBJECT

public:

  AlertListProxyModel(AlertListModel* sourceModel, QObject* parent = nullptr);
  ~AlertListProxyModel();

  void applyFilter(const QList<AlertFilter*>& filters);

  // QSortFilterProxyModel interface
protected:
  bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

private:
  bool passesAllQueries(int sourceRow) const;

  AlertListModel* m_sourceModel;
  QList<AlertFilter*> m_filters;
  mutable QHash<int, bool> m_rowsInModel;
};

} // Dsa

#endif // ALERTLISTPROXYMODEL_H
