// Map file into memory for faster processing
struct stat st{};
stat(args.inputs[fileNum], &st);
int fd = open(args.inputs[fileNum], O_RDONLY, 0);
if (fd < 0) {
  cerr << "Failed to open file " << args.inputs[fileNum] << ": " << strerror(fd) << endl;
  skippedFiles = true;
  continue;
}
void* data = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
if (data == MAP_FAILED) {
  cerr << "Failed to map file " << args.inputs[fileNum] << endl;
  perror("Cause:");
  skippedFiles = true;
  continue;
}
std::stringstream file;
file.rdbuf()->pubsetbuf(static_cast<char *>(data), st.st_size);

// Loop over each individual traceroute and process it
string line;
string baseSrc;
int time;
unsigned int count = 0;
vector<tuple<string, float>> rawHops(50);
while(getline(file, line)) {
  Document traceroute;
  traceroute.Parse(line.c_str())
  // ...
}