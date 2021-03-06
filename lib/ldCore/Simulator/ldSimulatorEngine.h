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

#ifndef LDSIMULATORENGINE_H
#define LDSIMULATORENGINE_H

#include <QtCore/QReadWriteLock>
#include <QtGui/QOpenGLFunctions>

#include "ldCore/ldCore_global.h"
#include "ldCore/Utilities/ldBasicDataStructures.h"

class QOpenGLShaderProgram;

class LDCORESHARED_EXPORT ldSimulatorEngine : protected QOpenGLFunctions
{
public:
    explicit ldSimulatorEngine();
    virtual ~ldSimulatorEngine();

    void addListener();
    void removeListener();

    bool isActive() const;

    void init();
    void drawLaserGeometry(QOpenGLShaderProgram *program);
    void pushVertexData(Vertex * data, unsigned int size);

private:
    GLuint vboIds[2] = {};

    ldVertexCircularBuffer m_buffer;
    QReadWriteLock m_lock;
    Vertex * vbuffer;

    int m_listenerCount = 0;
};

Q_DECLARE_METATYPE(ldSimulatorEngine*)

#endif // LDSIMULATORENGINE_H


