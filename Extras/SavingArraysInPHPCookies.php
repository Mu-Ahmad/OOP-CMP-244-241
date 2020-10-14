//If you have any better way to save arrays in PHP COOKIES do share below
//Try using each part with proper logic
//Have any error or query do let us know


/*****************************Saving Array in PHP Cookie********************************************

                      $cookie_name = "students";                                             
                      //create a student array ,it's keys can be numberical or string both
                      $cookie_value = array("bcs501"=>"Muhammad Bilal","bcs502"=>"Mujahid Ali");  
                      //json encode will make a string of the cookie_value array        
                      $array = json_encode($cookie_value);
                      //saving this will be same as saving a string in cookie
                      setcookie($cookie_name, $array, time() + (86400 * 30*365), "/"); // 86400*365 = 1 year

/*****************************************************************************************************  


/****************************Reading Array Cookie in PHP**********************************************
                     
                      $arr = (array)json_decode($_COOKIE[$cookie_name]);
                      foreach($arr as $x => $x_value) 
                      echo "Roll Number = ".$x." Name = ".$x_value."<br>";

/******************************************************************************************************


/**************************Modifieng Existing Array Cookie*********************************************
                      
                      //Adding more members to existing cookie array
                      $arr = (array)json_decode($_COOKIE[$cookie_name]); //json_decode return an object and then we are casting object to array
                      $arr = array_merge($arr,array("bcs538"=>"Saad Qayyum"));
                      //repeat the same process again to again same the modified array as json string
                      $array = json_encode($arr);
                      setcookie($cookie_name, $array, time() + (86400 * 30*365), "/"); // 86400 * 365 = 1 year

/*******************************************************************************************************                  
                      