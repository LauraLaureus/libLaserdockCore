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

#ifndef LDABSTRACTRENDERER_H
#define LDABSTRACTRENDERER_H
#include "ldCore/ldCore_global.h"

#include <QtCore/QObject>
#include "ldCore/Render/ldRendererManager.h"

class ldFrameBuffer;



class LDCORESHARED_EXPORT ldAbstractRenderer : public QObject
{
    Q_OBJECT
public:
    static const int DEFAULT_RATE;

    explicit ldAbstractRenderer(QObject *parent = 0);
    ldAbstractRenderer(ldRendererType type, QObject *parent = 0);

    ldRendererType type() {
        return m_type;
    }

    virtual void setBuffer(ldFrameBuffer * buffer){
        m_buffer = buffer;
    }

    virtual void render();

    // 30k or 20k currently
    void setRate(int rate);
    int rate() const;

private:
    ldRendererType m_type;
    ldFrameBuffer * m_buffer;

    int m_rate = DEFAULT_RATE;

};

#endif // LDABSTRACTRENDERER_H
