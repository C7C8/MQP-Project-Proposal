// Map file into memory for faster processing
struct stat st{};
stat(args.inputs[fileNum], &st);
int fd = open(args.inputs[fileNum], O_RDONLY, 0);
void* data = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
std::stringstream file;
file.rdbuf()->pubsetbuf(static_cast<char *>(data), st.st_size);

// Loop over each individual traceroute and process it
vector<tuple<string, float>> rawHops(50);
while(getline(file, line)) {
  Document traceroute;
  traceroute.Parse(line.c_str())
  // ...
}