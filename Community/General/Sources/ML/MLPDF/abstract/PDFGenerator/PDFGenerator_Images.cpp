//----------------------------------------------------------------------------------
//! The ML module class SavePDF.
/*!
// \file    PDFGenerator_Images.cpp
// \author  Axel Newe (axel.newe@fau.de)
// \date    2015-10-16
//
// Base class for PDF creators.
*/
//----------------------------------------------------------------------------------

// Local includes
#include "PDFGenerator.h"
#include "../../shared/MLPDF_Tools.h"


ML_START_NAMESPACE


//----------------------------------------------------------------------------------

mlPDF::IMAGE PDFGenerator::pdfDoc_LoadImageFromFile(std::string filename)
{
  mlPDF::IMAGE newImage = NULL;

  if (pdfDocument)
  {
    const unsigned int filenameLength = static_cast<unsigned int>(filename.length());

    std::string last4 = "";

    if ((filenameLength > 4) && (mlPDF::fileExists(filename)))
    {
      last4 = filename.substr(filenameLength - 4, 4);
      mlPDF::PDFTools::stringLower(last4);

      if (last4 == ".png")
      {
        newImage = HPDF_LoadPngImageFromFile(pdfDocument, filename.c_str());
      }
      else if ((last4 == ".jpg") || (last4 == ".jpeg"))
      {
        newImage = HPDF_LoadJpegImageFromFile(pdfDocument, filename.c_str());
      }

      if (newImage)
      {
        pdfDocImages.push_back(newImage);
      }
      else
      {
        _handleError("pdfDoc_LoadImageFromFile(std::string filename)");
      }

    }  // if ( (filenameLength > 4) && (fileExists(filename)) )

  } // if (pdfDocument)

  return newImage;
}

//----------------------------------------------------------------------------------

void PDFGenerator::pdfDoc_AddImage(float x, float y, float width, float height, mlPDF::IMAGE image, bool ignoreMargins)
{
  if ((pdfDocCurrentPage) && (image))
  {
    HPDF_Rect imageRect = _getPageRect(x, y, width, height, ignoreMargins);

    HPDF_STATUS result = HPDF_Page_DrawImage(pdfDocCurrentPage, image, imageRect.left, imageRect.bottom, width, height);
  
    if (result != HPDF_OK)
    {
      _handleError("pdfDoc_AddImage(float x, float y, float width, float height, mlPDF::IMAGE image, bool ignoreMargins)");
    }
  }
}

//----------------------------------------------------------------------------------

void PDFGenerator::pdfDoc_AddImage(float x, float y, float width, float height, std::string imageFilename, bool ignoreMargins)
{
  if (pdfDocCurrentPage)
  {
    HPDF_Rect imageRect = _getPageRect(x, y, width, height, ignoreMargins);

    HPDF_Image image = pdfDoc_LoadImageFromFile(imageFilename);

    if (image)
    {
      HPDF_STATUS result = HPDF_Page_DrawImage(pdfDocCurrentPage, image, imageRect.left, imageRect.bottom, width, height);

      if (result != HPDF_OK)
      {
        _handleError("pdfDoc_AddImage(float x, float y, float width, float height, std::string imageFilename, bool ignoreMargins)");
      }
    }
  }
}

//----------------------------------------------------------------------------------


ML_END_NAMESPACE