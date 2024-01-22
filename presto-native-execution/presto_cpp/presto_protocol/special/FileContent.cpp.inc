/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace facebook::presto::protocol {

static const std::pair<FileContent, json> FileContent_enum_table[] =
    { // NOLINT: cert-err58-cpp
        {FileContent::DATA, "DATA"},
        {FileContent::POSITION_DELETES, "POSITION_DELETES"},
        {FileContent::EQUALITY_DELETES, "EQUALITY_DELETES"}};

void to_json(json& j, const FileContent& e) {
  static_assert(
      std::is_enum<FileContent>::value, "FileContent must be an enum!");

  const auto* it = std::find_if(
      std::begin(FileContent_enum_table),
      std::end(FileContent_enum_table),
      [e](const std::pair<FileContent, json>& ej_pair) -> bool {
        return ej_pair.first == e;
      });
  j = ((it != std::end(FileContent_enum_table))
           ? it
           : std::begin(FileContent_enum_table))
          ->second;
}

void from_json(const json& j, FileContent& e) {
  static_assert(
      std::is_enum<FileContent>::value, "FileContent must be an enum!");

  const auto* it = std::find_if(
      std::begin(FileContent_enum_table),
      std::end(FileContent_enum_table),
      [&j](const std::pair<FileContent, json>& ej_pair) -> bool {
        return ej_pair.second == j;
      });
  e = ((it != std::end(FileContent_enum_table))
           ? it
           : std::begin(FileContent_enum_table))
          ->first;
}

} // namespace facebook::presto::protocol
