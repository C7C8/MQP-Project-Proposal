void saveToDb(const vector<tuple<string, string, float, int, bool> >& hops, pqxx::dbtransaction& cxn) {
  pqxx::stream_to stream(cxn, "hops", vector<string>{"src", "dst", "rtt", "time", "indirect"});
  for (const auto& hop : hops)
    stream << hop;
}