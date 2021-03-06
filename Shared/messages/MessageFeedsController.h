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

#ifndef MESSAGEFEEDSCONTROLLER_H
#define MESSAGEFEEDSCONTROLLER_H

// toolkit headers
#include "AbstractTool.h"

// Qt headers
#include <QAbstractListModel>

namespace Esri {
  namespace ArcGISRuntime {
    class GeoView;
    class Renderer;
    enum class SurfacePlacement;
  }
}

namespace Dsa {

class DataListener;

class LocationBroadcast;

class MessageFeedListModel;

class MessageFeedsController : public Esri::ArcGISRuntime::Toolkit::AbstractTool
{
  Q_OBJECT

  Q_PROPERTY(QAbstractListModel* messageFeeds READ messageFeeds CONSTANT)
  Q_PROPERTY(bool locationBroadcastEnabled READ isLocationBroadcastEnabled WRITE setLocationBroadcastEnabled NOTIFY locationBroadcastEnabledChanged)
  Q_PROPERTY(int locationBroadcastFrequency READ locationBroadcastFrequency WRITE setLocationBroadcastFrequency NOTIFY locationBroadcastFrequencyChanged)
  Q_PROPERTY(bool locationBroadcastInDistress READ isLocationBroadcastInDistress WRITE setLocationBroadcastInDistress NOTIFY locationBroadcastInDistressChanged)

public:
  static const QString RESOURCE_DIRECTORY_PROPERTYNAME;

  explicit MessageFeedsController(QObject* parent = nullptr);
  ~MessageFeedsController();

  void setGeoView(Esri::ArcGISRuntime::GeoView* geoView);

  QAbstractListModel* messageFeeds() const;

  QList<DataListener*> dataListeners() const;
  void addDataListener(DataListener* dataListener);
  void removeDataListener(DataListener* dataListener);

  QString toolName() const override;
  void setProperties(const QVariantMap& properties) override;

  QString resourcePath() const { return m_resourcePath; }
  void setResourcePath(const QString& resourcePath);

  LocationBroadcast* locationBroadcast() const;

  bool isLocationBroadcastEnabled() const;
  void setLocationBroadcastEnabled(bool enabled);

  int locationBroadcastFrequency() const;
  void setLocationBroadcastFrequency(int frequency);

  bool isLocationBroadcastInDistress() const;
  void setLocationBroadcastInDistress(bool inDistress);

  static Esri::ArcGISRuntime::SurfacePlacement toSurfacePlacement(const QString& surfacePlacement);

signals:
  void locationBroadcastEnabledChanged();
  void locationBroadcastFrequencyChanged();
  void locationBroadcastInDistressChanged();
  void toolErrorOccurred(const QString& errorMessage, const QString& additionalMessage);

private:
  Esri::ArcGISRuntime::Renderer* createRenderer(const QString& rendererInfo, QObject* parent = nullptr) const;

  Esri::ArcGISRuntime::GeoView* m_geoView = nullptr;

  MessageFeedListModel* m_messageFeeds = nullptr;
  QList<DataListener*> m_dataListeners;
  QString m_resourcePath;
  LocationBroadcast* m_locationBroadcast = nullptr;
};

} // Dsa

#endif // MESSAGEFEEDSCONTROLLER_H
