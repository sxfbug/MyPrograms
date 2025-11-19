// binance_client.cpp
#include <iostream>
#include <string>
#include <curl/curl.h> // 包含libcurl头文件
#include "nlohmann/json.hpp" // 解析json文件,use nlohmann


//存储币价格信息
class MarketDataClient
{
private:
    std::string name;
    double price;
public:
    // 这个回调函数会被libcurl在接收到数据时多次调用。
// 它的任务是将接收到的数据块（ptr）追加到我们提供的字符串（userdata）中。
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    // 计算数据块的实际大小
    size_t totalSize = size * nmemb;
    // 将 userp 指针转换回 std::string* 类型
    std::string* response = static_cast<std::string*>(userp);
    // 将数据块追加到字符串中
    response->append(static_cast<char*>(contents), totalSize);
    // 返回处理的数据大小，告诉libcurl我们处理成功了
    return totalSize;
}

    void get_NamePrice_byBinance(){
        // 初始化libcurl（全局只需做一次）
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    // 声明一个libcurl的“简单”句柄，这是我们所有操作的核心
    CURL* curl = curl_easy_init();
    // 用于存储API返回的JSON响应
    std::string responseBuffer;
    
    // 检查句柄是否初始化成功
    if(curl) {
        // 设置要请求的URL（币安BTC/USDT价格API）
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT");
        
        // 设置代理地址和端口（请替换为你自己主机的代理端口！）
        curl_easy_setopt(curl, CURLOPT_PROXY, "192.168.48.1:7897");

        // 设置SSL证书验证（对于生产环境，应保持开启。测试时可关闭，但不安全！
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L); // 1L 开启验证
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L); // 2L 严格主机验证

        // 设置响应数据的回调函数和存储位置
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer); // 传递responseBuffer的地址

        // 执行HTTP请求！
        CURLcode res = curl_easy_perform(curl);
        
        // 检查请求是否成功
        if(res != CURLE_OK) {
            // 失败，打印错误信息
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // 成功，打印原始的JSON响应
            std::cout << "API Response:\n" << responseBuffer << std::endl;
        }
        //把responseBuffer的内容转换为json
        auto jsonResponse = nlohmann::json::parse(responseBuffer);
        //读取json内容到struct,string可以转，但是不能直接从string到double
        //因为json本来就是一种特殊的string
        name=jsonResponse["symbol"];
        // 从JSON中获取字符串，然后使用std::stod将其转换为double
        
        price=std::stod(jsonResponse["price"].get<std::string>());
        
        //verify the transfomation
        std::cout<<"name: "<<name<<std::endl;
        std::cout<<"price: "<<price<<std::endl;

        // 无论成功与否，都要清理句柄
        curl_easy_cleanup(curl);
    }
    
    // 最后，进行libcurl的全局清理
    curl_global_cleanup();
    }
};








int main() {
    //实例化
    MarketDataClient btcusdt;
    btcusdt.get_NamePrice_byBinance();
    
    
    
    return 0;
}