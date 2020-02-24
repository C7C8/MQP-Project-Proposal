vector<tuple<string, float>> convertAtlas(const Document& traceroute) {
  vector<tuple<string, float>> hops;
  hops.reserve(traceroute["result"].Size());

  const auto& hopsArray = traceroute["result"].GetArray();
  for (const auto& hop : hopsArray) {
    // Verification -- not all hops have results
    if (!hop.HasMember("result"))
      continue;

    string src = getHopSource(hop["result"].GetArray());
    if (src.empty())
      hops.emplace_back("", -1); // Error condition for this hop

    hops.emplace_back(src, rttAverage(hop["result"].GetArray()));
  }

  return hops;
}

vector<tuple<string, float>> convertCaida(const Document& traceroute) {
  vector<tuple<string, float>> hops;
  hops.reserve(traceroute["hops"].GetArray().Size());

  for (const auto& hop : traceroute["hops"].GetArray())
    hops.emplace_back(hop["addr"].GetString(), hop["rtt"].GetFloat());

  return hops;
}