 #include <iostream>
 #include <counted.h>
 #include <vector>

 int main()
 {
   std::cout << "Tests: " << std::endl;

   Counted count1;
   Counted count2;
   Counted count3;

   std::cout << count1.getID() << std::endl;
   std::cout << count2.getID() << std::endl;
   std::cout << std::endl;

   Counted count4 = std::move(count3);
   std::cout << count3.getID() << std::endl;
   std::cout << count4.getID() << std::endl;
   std::cout << std::endl;

   //std::vector<Counted> vec;
   //vec.push_back(count4);
   //--------------------Task 2--------------------------
   auto myVec1 = std::vector<std::unique_ptr<Counted>>();
   myVec1.push_back(std::make_unique<Counted>());
   myVec1.push_back(std::make_unique<Counted>());

   for (const auto& i : myVec1)
   {
     std::cout << i->getID() << std::endl;
   }

   std::cout << std::endl;

   //--------------------Task 3a--------------------------
   auto myVec3 = std::vector<std::unique_ptr<Counted>>();
   myVec3.emplace_back(new Counted());
   myVec3.emplace_back(new Counted());

   for (const auto& i : myVec3)
   {
     std::cout << i->getID() << std::endl;
   }

   std::cout << std::endl;

   //--------------------Task 3b--------------------------
   auto count5 = std::make_unique<Counted>();
   auto count6 = std::make_unique<Counted>();

   auto myVec2 = std::vector<std::unique_ptr<Counted>>();
   myVec2.push_back(move(count5));
   myVec2.push_back(move(count6));

   for (const auto& i : myVec2)
   {
     std::cout << i->getID() << std::endl;
   }

   std::cout << std::endl;

   Counted count7;
   Counted count8;



   std::cout << "ENDENDENDEND" <<std::endl;

   return 0;
 }
