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

struct HiveTableLayoutHandle : public BaseHiveTableLayoutHandle {
  SchemaTableName schemaTableName = {};
  String tablePath = {};
  List<Column> dataColumns = {};
  List<HiveColumnHandle> partitionColumns = {};
  Map<String, String> tableParameters = {};
  Map<String, HiveColumnHandle> predicateColumns = {};
  std::shared_ptr<HiveBucketHandle> bucketHandle = {};
  std::shared_ptr<HiveBucketFilter> bucketFilter = {};
  String layoutString = {};
  std::shared_ptr<List<HiveColumnHandle>> requestedColumns = {};
  bool partialAggregationsPushedDown = {};
  bool appendRowNumber = {};
  bool footerStatsUnreliable = {};

  HiveTableLayoutHandle() noexcept;
};

void to_json(json& j, const HiveTableLayoutHandle& p);
void from_json(const json& j, HiveTableLayoutHandle& p);

} // namespace facebook::presto::protocol