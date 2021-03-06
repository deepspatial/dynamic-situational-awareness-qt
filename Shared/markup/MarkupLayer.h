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

#ifndef MARKUPLAYER_H
#define MARKUPLAYER_H

// C++ API headers
#include "FeatureCollectionLayer.h"
#include "JsonSerializable.h"

// Qt headers
#include <QHash>

namespace Esri {
namespace ArcGISRuntime {
class FeatureCollection;
class GraphicsOverlay;
class SimpleLineSymbol;
class Feature;
}
}

namespace Dsa {

class MarkupLayer : public Esri::ArcGISRuntime::FeatureCollectionLayer,
                    public Esri::ArcGISRuntime::JsonSerializable
{
  Q_OBJECT

public:
  ~MarkupLayer();

  // helper create methods
  static MarkupLayer* createFromPath(const QString& path, QObject* parent = nullptr);
  static MarkupLayer* createFromGraphics(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay, const QString& authorName, QObject* parent = nullptr);

  static QStringList colors();

  void setPath(const QString& path);
  QString path() const;
  Esri::ArcGISRuntime::FeatureCollection* featureCollection();
  QString author() const;

  // JSON Serializable
  static MarkupLayer* fromJson(const QString& json, QObject* parent = nullptr);
  QString toJson() const override;
  QJsonObject unknownJson() const override;
  QJsonObject unsupportedJson() const override;

private:
  MarkupLayer(const QString& json, Esri::ArcGISRuntime::FeatureCollection* featureCollection, QObject* parent = nullptr);

  QString m_path;
  QString m_json;
  QString m_author;
  Esri::ArcGISRuntime::FeatureCollection* m_featureCollection = nullptr;
  QHash<QUuid, QPair<Esri::ArcGISRuntime::Feature*, Esri::ArcGISRuntime::SimpleLineSymbol*>> m_featureHash;
};

} // Dsa

#endif // MARKUPLAYER_H
