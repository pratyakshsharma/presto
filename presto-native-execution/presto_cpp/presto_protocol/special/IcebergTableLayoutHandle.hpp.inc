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

// dependency BaseHiveTableLayoutHandle

namespace facebook::presto::protocol {

struct IcebergTableLayoutHandle : public BaseHiveTableLayoutHandle {
  List<IcebergColumnHandle> partitionColumns = {};
  List<Column> dataColumns = {};
  Map<String, IcebergColumnHandle> predicateColumns = {};
  std::shared_ptr<List<IcebergColumnHandle>> requestedColumns = {};
  IcebergTableHandle table = {};

  IcebergTableLayoutHandle() noexcept;
};

void to_json(json& j, const IcebergTableLayoutHandle& p);
void from_json(const json& j, IcebergTableLayoutHandle& p);

} // namespace facebook::presto::protocol