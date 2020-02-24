CREATE MATERIALIZED VIEW hops_aggregate_view AS (
  SELECT
    agg.src,
    agg.dst,
    agg.indirect,
    src_loc.coord as src_loc,
    dst_loc.coord as dst_loc,
    haversine_distance(src_loc.coord[0], src_loc.coord[1], dst_loc.coord[0], dst_loc.coord[1]) AS distance,
    agg.rtt_avg,
    agg.rtt_stdev,
    agg.rtt_range,
    agg.measurements
  FROM (
       SELECT hops.src,
          hops.dst,
          hops.indirect,
          AVG(RTT)        AS rtt_avg,
          STDDEV_SAMP(RTT)    AS rtt_stdev,
          MAX(RTT) - MIN(RTT)   AS rtt_range,
          COUNT(*)        AS measurements
       FROM hops
            INNER JOIN hops_stats hs
                 ON hops.src = hs.src
                  AND hops.dst = hs.dst
                  AND hs.stddev_samp != 0
                  AND hops.indirect = hs.indirect
                  AND ABS((hops.rtt - hs.avg) / hs.stddev_samp) <= 2
       GROUP BY (hops.dst, hops.src, hops.indirect)
     ) agg
       INNER JOIN locations src_loc ON agg.src = src_loc.ip
       INNER JOIN locations dst_loc ON agg.dst = dst_loc.ip
)