//
// Created by Ankit Batra on 5/5/21.
//

/* Given a url startUrl and an interface HtmlParser, implement a web crawler to crawl all links that are under
 * the same hostname as startUrl.
 * Return all urls obtained by your web crawler in any order.
 * Your crawler should:
 * Start from the page: startUrl
 * Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
 * Do not crawl the same link twice.
 * Explore only the links that are under the same hostname as startUrl. */

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string hostname;
public:
    string findHostname(string url) {
        string host = "";
        int idx = 0;
        while (idx < url.length()) {
            if (url[idx] == ':') {
                idx += 3;
                break;
            }
            idx++;
        }
        while (url[idx] != '/' && idx < url.length()) {
            host += url[idx];
            idx++;
        }
        return host;
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hostname = findHostname(startUrl);

        vector<string> result;

        vector<string> neighbors = htmlParser.getUrls(startUrl);
        queue<string> q;
        q.push(startUrl);
        for (string n : neighbors) {
            if (hostname == findHostname(n)) q.push(n);
        }

        unordered_set<string> visited;

        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (visited.count(s)) continue;
            result.push_back(s);
            visited.insert(s);
            vector<string> n = htmlParser.getUrls(s);
            for (string t : n) {
                if (hostname == findHostname(t) && visited.count(t) == 0) {
                    q.push(t);
                }
            }
        }
        return result;
    }
};

