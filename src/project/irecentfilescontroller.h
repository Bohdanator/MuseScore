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
#ifndef MU_PROJECT_IRECENTFILESCONTROLLER_H
#define MU_PROJECT_IRECENTFILESCONTROLLER_H

#include "modularity/imoduleinterface.h"

#include "projecttypes.h"

#include "async/notification.h"
#include "async/promise.h"

class QPixmap;

namespace mu::project {
class IRecentFilesController : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(IRecentFilesProvider)

public:
    virtual ~IRecentFilesController() = default;

    virtual const RecentFilesList& recentFilesList() const = 0;
    virtual async::Notification recentFilesListChanged() const = 0;

    virtual void prependRecentFile(const RecentFile& file) = 0;
    virtual void clearRecentFiles() = 0;

    virtual async::Promise<QPixmap> thumbnail(const RecentFile& file) const = 0;
};
}

#endif // MU_PROJECT_IRECENTFILESCONTROLLER_H
