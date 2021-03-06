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

#ifndef GRAPHICSOVERLAYALERTTARGET_H
#define GRAPHICSOVERLAYALERTTARGET_H

// example app headers
#include "AlertTarget.h"

namespace Esri {
namespace ArcGISRuntime {
class Graphic;
class GraphicsOverlay;
}
}

namespace Dsa {

class GeometryQuadtree;

class GraphicsOverlayAlertTarget : public AlertTarget
{
  Q_OBJECT

public:
  explicit GraphicsOverlayAlertTarget(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay);
  ~GraphicsOverlayAlertTarget();

  QList<Esri::ArcGISRuntime::Geometry> targetGeometries(const Esri::ArcGISRuntime::Envelope& targetArea) const override;
  QVariant targetValue() const override;

private:
  void setupGraphicConnections(Esri::ArcGISRuntime::Graphic* graphic);
  void rebuildQuadtree();

  Esri::ArcGISRuntime::GraphicsOverlay* m_graphicsOverlay = nullptr;
  GeometryQuadtree* m_quadtree = nullptr;
  QList<QMetaObject::Connection> m_graphicConnections;
};

} // Dsa

#endif // GRAPHICSOVERLAYALERTTARGET_H
