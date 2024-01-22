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

struct BaseHiveTableLayoutHandle : public ConnectorTableLayoutHandle {
  List<BaseHiveColumnHandle> partitionColumns = {};
  TupleDomain<Subfield> domainPredicate = {};
  std::shared_ptr<RowExpression> remainingPredicate = {};
  bool pushdownFilterEnabled = {};
  TupleDomain<std::shared_ptr<ColumnHandle>> partitionColumnPredicate = {};
};

void to_json(json& j, const BaseHiveTableLayoutHandle& p);
void from_json(const json& j, BaseHiveTableLayoutHandle& p);

} // namespace facebook::presto::protocol