#include <math.h>
#include <stdio.h>

int main(void) {
  printf("Enter the foundations' width (in metres):\t");
  double width = 0.0;
  scanf("%lf", &width);

  printf("Enter the foundations' height (in metres):\t");
  double height = 0.0;
  scanf("%lf", &height);

  printf("Enter the foundations' length (in metres):\t");
  double length = 0.0;
  scanf("%lf", &length);

  printf("Enter the concrete's price (in BGN per cubic metre):\t");
  double concrete_price_per_m3 = 0.0;
  scanf("%lf", &concrete_price_per_m3);

  double concrete_volume = width * height * length;
  double concrete_price = concrete_volume * concrete_price_per_m3;

  printf("Enter the capacity (in cubic metres) of the concrete truck:\t");
  double truck_capacity = 0.0;
  scanf("%lf", &truck_capacity);

  int n_trucks_needed = ceil(concrete_volume / truck_capacity);

  printf("Enter the distance to the construction site (in km):\t");
  double distance_to_site = 0.0;
  scanf("%lf", &distance_to_site);

  printf("Enter the fuel consumption rate (in litres per 100 km) of the concrete truck:\t");
  double fuel_consumption_rate = 0.0;
  scanf("%lf", &fuel_consumption_rate);

  // Double the fuel consumption to account for the return trip too.
  double fuel_consumption = fuel_consumption_rate * 2 * distance_to_site / 100;

  printf("Enter the fuel's price (in BGN per litre):\t");
  double fuel_price_per_l = 0.0;
  scanf("%lf", &fuel_price_per_l);

  double fuel_price = n_trucks_needed * fuel_consumption * fuel_price_per_l;
  double total_price = concrete_price + fuel_price;

  printf("The concrete's price (to the company) is %lf BGN.\n", concrete_price);
  printf("The fuel's price (to the company) is %lf BGN.\n", fuel_price);
  printf("The total price is %lf BGN.\n", total_price);
  
  return 0;
}
