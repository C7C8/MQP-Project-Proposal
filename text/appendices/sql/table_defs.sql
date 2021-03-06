CREATE TABLE hops (
    src         INET,
    dst         INET,
    rtt         REAL
);
CREATE INDEX src_index ON he USING HASH(src);
CREATE INDEX dst_src_BRIN_index ON hops USING brin(dst, src);

CREATE TABLE h0 PARTITION OF hops FOR VALUES FROM ('0.0.0.0') TO ('16.255.255.255');
CREATE TABLE h1 PARTITION OF hops FOR VALUES FROM ('16.255.255.255') TO ('32.255.255.255');
CREATE TABLE h2 PARTITION OF hops FOR VALUES FROM ('32.255.255.255') TO ('48.255.255.255');
CREATE TABLE h3 PARTITION OF hops FOR VALUES FROM ('48.255.255.255') TO ('64.255.255.255');
CREATE TABLE h4 PARTITION OF hops FOR VALUES FROM ('64.255.255.255') TO ('80.255.255.255');
CREATE TABLE h5 PARTITION OF hops FOR VALUES FROM ('80.255.255.255') TO ('96.255.255.255');
CREATE TABLE h6 PARTITION OF hops FOR VALUES FROM ('96.255.255.255') TO ('112.255.255.255');
CREATE TABLE h7 PARTITION OF hops FOR VALUES FROM ('112.255.255.255') TO ('128.255.255.255');
CREATE TABLE h8 PARTITION OF hops FOR VALUES FROM ('128.255.255.255') TO ('144.255.255.255');
CREATE TABLE h9 PARTITION OF hops FOR VALUES FROM ('144.255.255.255') TO ('160.255.255.255');
CREATE TABLE hA PARTITION OF hops FOR VALUES FROM ('160.255.255.255') TO ('176.255.255.255');
CREATE TABLE hB PARTITION OF hops FOR VALUES FROM ('176.255.255.255') TO ('192.255.255.255');
CREATE TABLE hC PARTITION OF hops FOR VALUES FROM ('192.255.255.255') TO ('208.255.255.255');
CREATE TABLE hD PARTITION OF hops FOR VALUES FROM ('208.255.255.255') TO ('224.255.255.255');
CREATE TABLE hE PARTITION OF hops FOR VALUES FROM ('224.255.255.255') TO ('240.255.255.255');
CREATE TABLE hF PARTITION OF hops FOR VALUES FROM ('240.255.255.255') TO ('255.255.255.255');
CREATE TABLE hZ PARTITION OF hops FOR VALUES FROM ('::') TO ('FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF');
