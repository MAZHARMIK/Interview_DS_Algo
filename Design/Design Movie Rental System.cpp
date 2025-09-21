/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/design-movie-rental-system/
*/


/***************************************************************** C++ *****************************************************************/
// Approach (Set for ordered storage, Unordered Map for quick lookup)
// T.C. : 
// MovieRentingSystem() -> O(n log n) for n entries (insert each entry into sets)
// search(movie)        -> O(5) i.e. constant. We access the movie set in O(1) from map and then return first 5 elements
// rent(shop, movie)    -> O(log m + log r) per operation
//                         (log m to erase from available[movie], log r to insert into rented, r = total rented movies)
// drop(shop, movie)    -> O(log m + log r) per operation
// report()             -> O(5) i.e. constant

// S.C. : 
// O(n + r) total
// available          -> O(n) (sum of all available movies)
// movieToShopPrice   -> O(n) (sum of all shop-price pairs)
// rented             -> O(r) (r = total rented movies)
class MovieRentingSystem {
    typedef pair<int,int> P;
    unordered_map<int, set<P>> available;        // movie -> {price, shop}
    unordered_map<int, set<P>> movieToShopPrice; // movie -> {shop, price}
    set<tuple<int,int,int>> rented;              // {price, shop, movie}

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &entry : entries) {
            int shop  = entry[0];
            int movie = entry[1];
            int price = entry[2];
            available[movie].insert({price, shop});
            movieToShopPrice[movie].insert({shop, price});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        if (available.count(movie)) {
            for (auto &[price, shop] : available[movie]) {
                result.push_back(shop);
                if (++count >= 5)
                    break;
            }
        }
        return result;
    }

    void rent(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto &[price, shop, movie] : rented) {
            result.push_back({shop, movie});
            if (++count >= 5)
                break;
        }
        return result;
    }
};


/***************************************************************** JAVA *****************************************************************/
// Approach (TreeSet for ordered storage, HashMap for quick lookup)
// T.C. : 
// MovieRentingSystem() -> O(n log n) for n entries (insert each entry into TreeSets)
// search(movie)        -> O(5) i.e. constant time to return first 5 cheapest shops
// rent(shop, movie)    -> O(log m + log r) per operation
//                         (log m to remove from available TreeSet of that movie, log r to insert into rented TreeSet)
// drop(shop, movie)    -> O(log m + log r) per operation
//                         (log m to insert back to available TreeSet, log r to remove from rented TreeSet)
// report()             -> O(5) i.e. constant time to return top 5 rented movies

// S.C. : 
// O(n + r) total
// available          -> O(n) (sum of all available movies)
// movieToShopPrice   -> O(n) (sum of all shop-price mappings)
// rented             -> O(r) (r = total rented movies)
class MovieRentingSystem {

    class PriceShop implements Comparable<PriceShop> {
        int price, shop;
        PriceShop(int price, int shop) { this.price = price; this.shop = shop; }
        public int compareTo(PriceShop o) {
            if (this.price != o.price) return this.price - o.price;
            return this.shop - o.shop;
        }
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof PriceShop)) return false;
            PriceShop p = (PriceShop) o;
            return price == p.price && shop == p.shop;
        }
        @Override
        public int hashCode() { return Objects.hash(price, shop); }
    }

    class RentedMovie implements Comparable<RentedMovie> {
        int price, shop, movie;
        RentedMovie(int price, int shop, int movie) {
            this.price = price; this.shop = shop; this.movie = movie;
        }
        public int compareTo(RentedMovie o) {
            if (this.price != o.price) return this.price - o.price;
            if (this.shop != o.shop) return this.shop - o.shop;
            return this.movie - o.movie;
        }
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof RentedMovie)) return false;
            RentedMovie r = (RentedMovie) o;
            return price == r.price && shop == r.shop && movie == r.movie;
        }
        @Override
        public int hashCode() { return Objects.hash(price, shop, movie); }
    }

    Map<Integer, TreeSet<PriceShop>> available;      // movie -> {price, shop}
    Map<Integer, Map<Integer, Integer>> movieToShopPrice; // movie -> (shop -> price)
    TreeSet<RentedMovie> rented;                     // sorted rented movies

    public MovieRentingSystem(int n, int[][] entries) {
        available = new HashMap<>();
        movieToShopPrice = new HashMap<>();
        rented = new TreeSet<>();

        for (int[] e : entries) {
            int shop = e[0], movie = e[1], price = e[2];

            available.computeIfAbsent(movie, k -> new TreeSet<>()).add(new PriceShop(price, shop));
            movieToShopPrice.computeIfAbsent(movie, k -> new HashMap<>()).put(shop, price);
        }
    }

    public List<Integer> search(int movie) {
        List<Integer> res = new ArrayList<>();
        if (available.containsKey(movie)) {
            int count = 0;
            for (PriceShop ps : available.get(movie)) {
                res.add(ps.shop);
                if (++count >= 5) break;
            }
        }
        return res;
    }

    public void rent(int shop, int movie) {
        int price = movieToShopPrice.get(movie).get(shop);
        available.get(movie).remove(new PriceShop(price, shop));
        rented.add(new RentedMovie(price, shop, movie));
    }

    public void drop(int shop, int movie) {
        int price = movieToShopPrice.get(movie).get(shop);
        available.get(movie).add(new PriceShop(price, shop));
        rented.remove(new RentedMovie(price, shop, movie));
    }

    public List<List<Integer>> report() {
        List<List<Integer>> res = new ArrayList<>();
        int count = 0;
        for (RentedMovie rm : rented) {
            res.add(Arrays.asList(rm.shop, rm.movie));
            if (++count >= 5) break;
        }
        return res;
    }
}
