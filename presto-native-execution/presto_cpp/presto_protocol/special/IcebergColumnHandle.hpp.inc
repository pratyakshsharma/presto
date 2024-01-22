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

// dependency BaseHiveColumnHandle

namespace facebook::presto::protocol {

struct IcebergColumnHandle : public BaseHiveColumnHandle {
  ColumnIdentity columnIdentity = {};
  Type type = {};

  IcebergColumnHandle() noexcept;

  bool operator<(const ColumnHandle& o) const override {
    return name < dynamic_cast<const IcebergColumnHandle&>(o).name;
  }
};

void to_json(json& j, const IcebergColumnHandle& p);
void from_json(const json& j, IcebergColumnHandle& p);

} // namespace facebook::presto::protocol