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

#include "FeatureQueryResultManager.h"

// C++ API headers
#include "FeatureQueryResult.h"

using namespace Esri::ArcGISRuntime;

namespace Dsa {

/*!
  \class Dsa::FeatureQueryResultManager
  \inmodule Dsa
  \brief RAII helper to ensure the \l Esri::ArcGISRuntime::FeatureQueryResult*
  is deleted when we leave the scope.
 */

/*!
  \brief Constructor taking an \l Esri::ArcGISRuntime::FeatureQueryResult \a results.
 */
FeatureQueryResultManager::FeatureQueryResultManager(FeatureQueryResult* results):
  m_results(results)
{

}

/*!
  \brief Destructor.
 */
FeatureQueryResultManager::~FeatureQueryResultManager()
{
  delete m_results;
}

} // Dsa
