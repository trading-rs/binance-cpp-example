#include <binance/binance.hpp>
using namespace binance::endpoint;
using namespace binance::extra;

#include <memory>
#include <utility>
#include <string>
using namespace std;

const char* api_key = getenv("BINANCE_API_KEY");
const char* api_secret = getenv("BINANCE_API_SECRET");

auto pre_check() {
  if (!(api_key && api_secret))
    throw runtime_error("Please setup binance APIKEY and APISECRET!");
}

int main(int argc, char** argv) {
  pre_check();
  auto endpoint = make_shared<Endpoint>(api_key, api_secret);

  endpoint->ping() >>= print_result<json>;
  endpoint->time() >>= print_result<long>;
  endpoint->all_prices() >>= print_results<TickerPrice>;
  endpoint->buy_limit("ETHBTC", 1.0, 0.069) >>= print_result<NewOrderResponse>;
}
