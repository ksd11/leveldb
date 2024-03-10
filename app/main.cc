#include <cassert>
#include <iostream>

#include "leveldb/db.h"

int main() {
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);

  std::string value = "value";
  leveldb::Slice key1 = "key1";
  leveldb::Slice key2 = "key2";
  leveldb::Slice key4 = "key3";

  // put
  /* leveldb::Status s = db->Put(leveldb::WriteOptions(), key1, value);

  if (s.ok()) s = db->Get(leveldb::ReadOptions(), key1, &value);

  if (s.ok()) s = db->Delete(leveldb::WriteOptions(), key1); */

  leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);

  std::cout << value << std::endl;

  assert(status.ok());
}