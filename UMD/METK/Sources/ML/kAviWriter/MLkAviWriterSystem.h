//----------------------------------------------------------------------------------
//
// Copyright 2001-2004, MeVis gGmbH
// ALL RIGHTS RESERVED
//
// THE CONTENT OF THIS WORK CONTAINS CONFIDENTIAL AND PROPRIETARY
// INFORMATION OF MEVIS GGMBH. ANY DUPLICATION, MODIFICATION,
// DISTRIBUTION, OR DISCLOSURE IN ANY FORM, IN WHOLE, OR IN PART, IS STRICTLY
// PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF MEVIS GGMBH
//
//----------------------------------------------------------------------------------
//! Project global and OS specific declarations.
/*!
// \file    MLkAviWriterSystem.h
// \author  okonrad
// \date    2005-07-21
//
*/
// Last changed by $Author: okonrad $
// $Id: MLkAviWriterSystem.h 27281 2005-07-28 12:28:23Z okonrad $
// $Source$
//----------------------------------------------------------------------------------


#ifndef __MLkAviWriterSystem_H
#define __MLkAviWriterSystem_H



// DLL export macro definition
#if defined (ML_LIBRARY_EXPORT_ATTRIBUTE) || defined (ML_LIBRARY_IMPORT_ATTRIBUTE)
  // Make use of the new style and platform independent import/export definitions.
  #ifdef MLKAVIWRITER_EXPORTS
    // Export library symbols.
    #define MLKAVIWRITER_EXPORT   ML_LIBRARY_EXPORT_ATTRIBUTE
  #else
    // If included by external modules, exported symbols are declared as import symbols
    #define MLKAVIWRITER_EXPORT   ML_LIBRARY_IMPORT_ATTRIBUTE
  #endif
#else
  // Only for backward compatibility to versions < MeVisLab2.2.
  #ifdef WIN32
  #ifdef MLKAVIWRITER_EXPORTS
  // Use the MLKAVIWRITER_EXPORT macro to export classes and functions
  #define MLKAVIWRITER_EXPORT __declspec(dllexport)
  #else
  // If included by external modules, exported symbols are declared as import symbols
  #define MLKAVIWRITER_EXPORT __declspec(dllimport)
  #endif

  #else
  // No export declarations are necessary for non-Windows systems
  #define MLKAVIWRITER_EXPORT
  #endif
#endif

#endif // __MLkAviWriterSystem_H


