/****************************************************************************
   Copyright (C) 2008-2024 Pedro Lopez-Cabanillas <plcl@users.sf.net>         

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
****************************************************************************/

#ifndef DIALSTYLES_H
#define DIALSTYLES_H

#include <QObject>
#include <QStyle>
#include <QWidget>
#include "ui_dialstyles.h"

class DialStyles : public QWidget
{
    Q_OBJECT

public:
    DialStyles(QWidget *parent = 0);
    ~DialStyles() override;

public slots:
    void styleComboChanged(QString styleName);
    void showNotches(bool bShow);

private:
    Ui::DialStylesUIClass ui;
    QStyle *m_style;
};

#endif // DIALSTYLES_H
