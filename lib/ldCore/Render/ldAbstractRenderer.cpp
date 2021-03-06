/**
    libLaserdockCore
    Copyright(c) 2018 Wicked Lasers

    This file is part of libLaserdockCore.

    libLaserdockCore is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libLaserdockCore is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libLaserdockCore.  If not, see <https://www.gnu.org/licenses/>.
**/

#include "ldAbstractRenderer.h"

#include <QtDebug>

/*!
    \enum ldRendererType
    \brief the list of supported renderer types.

*/

/*!
  \class ldAbstractRenderer
  \brief Abstract class for a renderer.
  \inmodule rendering

  The abstsract class for renderer defines a very simple interface. It contains the type of renderer specified by using enum \l ldRendererType.
  Also prvides method to setting \l ldFrameBuffer that is used by its subclasses.

*/


const int ldAbstractRenderer::DEFAULT_RATE = 30000;

/*!
  \brief default constructor, with type set to UNINITIALIZED

*/
ldAbstractRenderer::ldAbstractRenderer(QObject *parent) :
    QObject(parent),
    m_type(UNINITIALIZED)
  , m_buffer(NULL)
{

}

/*!
    \brief overloaded constructor, with additional parameter specifying the type.
*/
ldAbstractRenderer::ldAbstractRenderer(ldRendererType type, QObject *parent) :
    QObject(parent),
    m_type(type)
  , m_buffer(NULL)
{


}

/*!
    \brief empty virtual method, to be overrided by subclasses.
*/
void ldAbstractRenderer::render(){

}


void ldAbstractRenderer::setRate(int rate)
{
    if(!(rate == 20000 || rate == 30000)) {
        qWarning() << "Wrong rate value " << rate;
        return;
    }

    m_rate = rate;
}

int ldAbstractRenderer::rate() const
{
    return m_rate;
}

/*!
  \fn ldRendererType ldAbstractRenderer::type()
  \brief returns the type of the renderer this class is.
*/


/*!
  \fn void ldAbstractRenderer::setBuffer(ldFrameBuffer * buffer)
  \brief sets the buffer needed by renderer.
*/
