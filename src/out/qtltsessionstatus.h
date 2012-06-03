/**
 * Copyright (c) 2012, WebItUp
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef QTLTSESSIONSTATUS_H
#define QTLTSESSIONSTATUS_H

#include <QtCore/QObject>

/*! \cond */

namespace RoxeeTorrent
{
    class QtLtSessionStatus : public QObject
    {
        Q_OBJECT
    public:
        explicit QtLtSessionStatus(QObject *parent = 0);

    //    Q_PROPERTY(const bool has_incoming_connections READ has_incoming_connections)

    signals:

    public slots:

    };
}

/*! \endcond */

#endif // QTLTSESSIONSTATUS_H

/*
status()
session_status status() const;
status() returns session wide-statistics and status. The session_status struct has the following members:

struct dht_lookup
{
        char const* type;
        int outstanding_requests;
        int timeouts;
        int responses;
        int branch_factor;
};

struct session_status
{
        bool has_incoming_connections;

        int upload_rate;
        int download_rate;
        size_type total_download;
        size_type total_upload;

        int payload_upload_rate;
        int payload_download_rate;
        size_type total_payload_download;
        size_type total_payload_upload;

        int ip_overhead_upload_rate;
        int ip_overhead_download_rate;
        size_type total_ip_overhead_download;
        size_type total_ip_overhead_upload;

        int dht_upload_rate;
        int dht_download_rate;
        size_type total_dht_download;
        size_type total_dht_upload;

        int tracker_upload_rate;
        int tracker_download_rate;
        size_type total_tracker_download;
        size_type total_tracker_upload;

        size_type total_redundant_bytes;
        size_type total_failed_bytes;

        int num_peers;
        int num_unchoked;
        int allowed_upload_slots;

        int optimistic_unchoke_counter;
        int unchoke_counter;

        int dht_nodes;
        int dht_node_cache;
        int dht_torrents;
        int dht_global_nodes;
        std::vector<dht_lookup> active_requests;
};
*/
