/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "testing/environment.h"

#include "fonts/fontsmodule.h"
#include "draw/drawmodule.h"
#include "engraving/engravingmodule.h"
#include "importexport/musicxml/musicxmlmodule.h"

#include "log.h"

static mu::testing::SuiteEnvironment musicxml_se(
{
    new mu::draw::DrawModule(),
    new mu::fonts::FontsModule(), // needs for libmscore
    new mu::engraving::EngravingModule(),
    new mu::iex::musicxml::MusicXmlModule() // needs for init resources
},
    []() {
    LOGI() << "musicxml tests suite post init";
}
    );
