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

#include "dialstyles.h"
#include "ClassicStyle.h"
#include "PeppinoStyle.h"
#include "SkulptureStyle.h"
#include "VokiStyle.h"

DialStyles::DialStyles(QWidget *parent)
    : QWidget(parent)
    , m_style(nullptr)
{
    ui.setupUi(this);
    ui.cboStyles->addItems({"Legacy", "Classic", "Peppino", "Skulpture", "Vokimon"});

    styleComboChanged("Legacy");
    connect(ui.cboStyles, &QComboBox::currentTextChanged, this, &DialStyles::styleComboChanged);
    connect(ui.chkbNotches, &QCheckBox::toggled, this, &DialStyles::showNotches);
}

DialStyles::~DialStyles()
{
    delete m_style;
}

void DialStyles::showNotches(bool bShow)
{
    QList<QDial *> all = findChildren<QDial *>();
    foreach (QDial *d, all) {
        d->setNotchesVisible(bShow);
    }
}

void DialStyles::styleComboChanged(QString styleName)
{
    delete m_style;

    if (styleName == "Classic") {
        m_style = new ClassicStyle();
    } else if (styleName == "Peppino") {
        m_style = new PeppinoStyle();
    } else if (styleName == "Skulpture") {
        m_style = new SkulptureStyle();
    } else if (styleName == "Vokimon") {
        m_style = new VokiStyle();
    } else {
        m_style = nullptr;
    }

    QList<QDial *> all = findChildren<QDial *>();
    foreach (QDial *d, all) {
        d->setStyle(m_style);
    }
}
