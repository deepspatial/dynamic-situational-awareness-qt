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

#ifndef ABSTRACTSKETCHTOOL_H
#define ABSTRACTSKETCHTOOL_H

// toolkit headers
#include "AbstractTool.h"

// C++ API headers
#include "GeometryTypes.h"

// Qt headers
#include <QList>

namespace Esri {
  namespace ArcGISRuntime {
    class GeoView;
    class GraphicsOverlay;
    class GeometryBuilder;
    class Graphic;
    class Symbol;
    class Geometry;
    class Point;
  }
}

namespace Dsa {

class AbstractSketchTool : public Esri::ArcGISRuntime::Toolkit::AbstractTool
{
  Q_OBJECT

public:
  explicit AbstractSketchTool(QObject* parent = nullptr);
  ~AbstractSketchTool();

  void initGeometryBuilder();
  void replaceGeometry(Esri::ArcGISRuntime::Geometry geometry);
  Esri::ArcGISRuntime::Geometry builderGeometry() const;

  bool isMultiPartBuilder() const;
  virtual Esri::ArcGISRuntime::GeometryType geometryType() const = 0;

  void clear();
  int addPart();
  void selectPartByIndex(int partIndex);
  void insertPointInPart(int partIndex, int pointIndex, const Esri::ArcGISRuntime::Point& drawPoint);
  Esri::ArcGISRuntime::Point normalizedPoint(double x, double y);

  Esri::ArcGISRuntime::GraphicsOverlay* sketchOverlay() const;

  // Functions that should be from the SketchEditor
  void setSketchSymbol(Esri::ArcGISRuntime::Symbol* symbol);
  Esri::ArcGISRuntime::Symbol* sketchSymbol();

protected:
  virtual void updateSketch() = 0;

  QList<Esri::ArcGISRuntime::Graphic*> m_partOutlineGraphics;
  Esri::ArcGISRuntime::GraphicsOverlay* m_sketchOverlay = nullptr;
  Esri::ArcGISRuntime::GeometryBuilder* m_geometryBuilder = nullptr;
  Esri::ArcGISRuntime::GeoView* m_geoView = nullptr;
  int m_selectedPartIndex = 0;

  // members that should be from the SketchEditor
  Esri::ArcGISRuntime::Symbol* m_sketchSymbol = nullptr;
};

} // Dsa

#endif // ABSTRACTSKETCHTOOL_H
