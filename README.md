# DuboTorrent

This is a (very) thin layer on top of rasterbar libtorrent that exposes a uniform scriptable API for it.

It is primarily meant to serve as part of the Dubo webrunner application, though other people might find interest in it.
It's released with the same license as libtorrent itself.

Note that it's tested linking to libtorrent 0.16.0 using the following config:
geoip=static timer=boost ipv6=on iconv=on asserts=off windows-version=xp dht-support=on encryption=tommath resolve-countries=on character-set=unicode deprecated-functions=off logging=none

Licensed under BSD2.

## Caveats

Building on windows is a fucking pain in the bozoum.

If you plan on using mingw, it's quite likely you will need to edit the Makefile by hand, and APPEND -lws2_32 -lwsock32.
See http://mingw-users.1079350.n2.nabble.com/Link-to-ws2-32-or-wsock32-td6332441.html
