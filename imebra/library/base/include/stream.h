/*

Imebra 2011 build 2011-09-18_22-24-41

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 by Paolo Brandoli
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE FREEBSD PROJECT ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FREEBSD PROJECT OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the authors
 and should not be interpreted as representing official policies, either expressed or implied,
 of the Imebra Project.

Imebra is available at http://imebra.com



*/

/*! \file stream.h
    \brief Declaration of the stream class.

*/

#if !defined(imebraStream_3146DA5A_5276_4804_B9AB_A3D54C6B123A__INCLUDED_)
#define imebraStream_3146DA5A_5276_4804_B9AB_A3D54C6B123A__INCLUDED_

#include "baseStream.h"

#include <ios>
#include <stdio.h>

///////////////////////////////////////////////////////////
//
// Everything is in the namespace puntoexe
//
///////////////////////////////////////////////////////////
namespace puntoexe
{

/// \addtogroup group_baseclasses
///
/// @{

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
/// \brief This class derives from the baseStream 
///         class and implements a file stream.
///
/// This class can be used to read/write on physical files
///  in the mass storage.
///
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
class stream : public baseStream
{
protected:
	// Destructor
	///////////////////////////////////////////////////////////
	virtual ~stream();

public:
	// Constructor
	///////////////////////////////////////////////////////////
	stream(): m_openFile(0){}

	/// \brief Open a file.
	///
	/// The function uses the standard library function
	///  fopen to open the specified file.
	///
	/// The created file object will be automatically
	///  closed and destroyed when one of the following events
	///  will occur:
	/// - the stream class will be destroyed
	/// - this function will be called again
	///
	/// @param fileName the name of the file to be opened
	/// @param mode     the opening mode.
	///                 Can be the combination of one or
	///                 more of the following values:
	///                 - ios_base::in the file will be opened
	///                   for reading operations
	///                 - ios_base::out the file will be
	///                   opened for writing operations
	///                 - ios_base::app the writing operations
	///                   will append data to the existing file
	///                 - ios_base::trunc the existing file
	///                   will be truncated to zero length
	///                 - ios_base::binary the file will be
	///                   opened in binary mode. Please note
	///                   that this flag is useless, since all
	///                   the files ARE OPENED IN BINARY MODE.
	///
	///////////////////////////////////////////////////////////
	void openFile(const std::string& fileName, const int mode);

	void openFile(const std::wstring& fileName, const int mode);

	///////////////////////////////////////////////////////////
	//
	// Virtual stream's functions
	//
	///////////////////////////////////////////////////////////
	virtual void write(imbxUint32 startPosition, const imbxUint8* pBuffer, imbxUint32 bufferLength);
	virtual imbxUint32 read(imbxUint32 startPosition, imbxUint8* pBuffer, imbxUint32 bufferLength);

protected:
	FILE* m_openFile;
};

///@}

} // namespace puntoexe


#endif // !defined(imebraStream_3146DA5A_5276_4804_B9AB_A3D54C6B123A__INCLUDED_)
