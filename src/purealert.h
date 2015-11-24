/*
Copyright (C) 2014 - 2015 Eaton

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

/*! \file purealert.h
 *  \author Alena Chernikava <AlenaChernikava@Eaton.com>
 *  \brief General representation of alert
 */
#ifndef SRC_PUREALERT_H
#define SRC_PUREALERT_H

#include <string>
#include <vector>

#define ALERT_UNKNOWN  "UNKNOWN"
#define ALERT_START    "ACTIVE"
#define ALERT_ACK1     "ACK-WIP"
#define ALERT_ACK2     "ACK-PAUSE"
#define ALERT_ACK3     "ACK-IGNORE"
#define ALERT_ACK4     "ACK-SILENCE"
#define ALERT_RESOLVED "RESOLVED"


class PureAlert{
 public:
    std::string _status;
    int64_t _timestamp;
    std::string _description;
    std::string _element;
    std::string _severity;
    std::vector <std::string> _actions;

    PureAlert() { _timestamp = 0; };
    PureAlert(const std::string &s, int64_t tm, const std::string &descr, const std::string &element_name)
    {
        _status = s;
        _timestamp = tm;
        _description = descr;
        _element = element_name;
    };

    PureAlert(const std::string &s, int64_t tm, const std::string &descr, const std::string &element_name, const std::string &severity, const std::vector<std::string> &actions)
    {
        _status = s;
        _timestamp = tm;
        _description = descr;
        _element = element_name;
        _severity = severity;
        _actions = actions;
    };

    static bool isStatusKnown (const char *status);
    void print(void) const;
};

#endif // SRC_PURE_ALERT_H_
