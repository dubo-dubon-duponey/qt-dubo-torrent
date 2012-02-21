#ifndef QTLTSESSIONSTATUS_H
#define QTLTSESSIONSTATUS_H

#include <QObject>

class QtLtSessionStatus : public QObject
{
    Q_OBJECT
public:
    explicit QtLtSessionStatus(QObject *parent = 0);
    
//    Q_PROPERTY(const bool has_incoming_connections READ has_incoming_connections)

signals:
    
public slots:
    
};

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
