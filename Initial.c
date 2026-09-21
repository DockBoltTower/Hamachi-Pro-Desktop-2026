#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

double getValue(Product product) {
    return product.price * product.quantity;
}

void printProduct(Product product) {
    printf(
        "%-15s | %3d units | $%8.2f | Value: $%9.2f\n",
        product.name,
        product.quantity,
        product.price,
        getValue(product)
    );
}

int main() {
    Product products[] = {
        {"Laptop", 5, 899.99},
        {"Keyboard", 12, 79.50},
        {"Mouse", 20, 39.99},
        {"Monitor", 8, 249.99},
        {"Headphones", 15, 129.99}
    };

    int count = sizeof(products) / sizeof(products[0]);
    double total = 0.0;
    Product mostValuable = products[0];

    printf("Warehouse Report\n");
    printf("================\n");

    for (int i = 0; i < count; i++) {
        printProduct(products[i]);

        total += getValue(products[i]);

        if (getValue(products[i]) > getValue(mostValuable)) {
            mostValuable = products[i];
        }
    }

    printf("================\n");
    printf("Products: %d\n", count);
    printf("Total Value: $%.2f\n", total);
    printf("Most Valuable: %s\n", mostValuable.name);
    printf("Item Value: $%.2f\n", getValue(mostValuable));

    return 0;
}