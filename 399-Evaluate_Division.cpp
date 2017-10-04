class Solution {
public:
    double calcDFS(unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& record, const string& source, const string& target, double value) {
        if ( record.find(source) != record.end() ) return -1;
        if ( graph[source].find(target) != graph[source].end() ) return graph[source][target] * value;
        double ret;
        record.insert(source);
        for ( auto& p : graph[source] ) {
            ret = calcDFS(graph, record, p.first, target, p.second*value);
            if ( ret != double(-1) ) return ret;
        }
        record.erase(source);
        return -1;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        unordered_set<string> record;
        vector<double> result; result.reserve(queries.size());
        double value;
        for ( int i = 0; i < equations.size(); ++i ) {
            graph[equations[i].first][equations[i].second] = values[i];
            graph[equations[i].second][equations[i].first] = 1 / values[i];
        }
        for ( auto &p : queries ) {
            value = -1;
            if ( graph.find(p.first) != graph.end() && graph.find(p.second) != graph.end() ) {
                record.clear();
                value = calcDFS(graph, record, p.first, p.second, 1);
            }
            result.push_back(value);
        }
        return result;
    }
};
