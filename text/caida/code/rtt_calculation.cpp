if (args.ping_given) {
  // Ping mode -- just do one entry, source to final destination
  float rtt = get<1>(rawHops[rawHops.size() - 1]);
  if (rtt < 0)
    continue; // Can't parse this traceroute
  hops.emplace_back(baseSrc, get<0>(rawHops[rawHops.size() - 1]), rtt, time, false);
} else {
  // Either direct or calculated mode
  int j = -1;
  for (auto& hop : rawHops) {
    j++;

    // Add a hop for the direct source-> hop entry
    if (get<1>(hop) < 0 || get<0>(hop).empty())
      continue; // Bad hop
    hops.emplace_back(baseSrc, get<0>(hop), get<1>(hop), time, false);

    // If we're not on calculate mode OR we're at the first hop, skip. Processing the first hop would be
    // redundant since direct mode already picks it up.
    if (!args.calculate_given || j == 0)
      continue;

    // Make sure the last hop is valid, otherwise we can't calculate an rtt
    tuple<string, float> lastHop = rawHops[j - 1];
    if (get<0>(lastHop).empty() || get<1>(lastHop) < 0)
      continue;

    hops.emplace_back(get<0>(lastHop), get<0>(hop), get<1>(hop) - get<1>(lastHop), time, true);
  }
}