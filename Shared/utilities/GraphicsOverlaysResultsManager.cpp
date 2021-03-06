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

// PCH header
#include "pch.hpp"

#include "GraphicsOverlaysResultsManager.h"

// C++ API headers
#include "IdentifyGraphicsOverlayResult.h"

using namespace Esri::ArcGISRuntime;

namespace Dsa {

/*!
  \class Dsa::GraphicsOverlaysResultsManager
  \brief RAII helper to ensure the list of \l Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult* objects
  is deleted when we leave the scope.
 */

/*!
  \brief Constructor taking a list of  \l Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult \a results.
 */
GraphicsOverlaysResultsManager::GraphicsOverlaysResultsManager(const QList<Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult*>& results):
  m_results(results)
{

}

/*!
  \brief Destructor.
 */
GraphicsOverlaysResultsManager::~GraphicsOverlaysResultsManager()
{
  qDeleteAll(m_results);
}

} // Dsa
