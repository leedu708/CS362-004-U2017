/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   int size = 15;
	   String[] urls = new String[size];
	   
	   urls[0] = "http://www.amazon.com";
	   urls[1] = "http://////www.google.com";
	   urls[2] = "http://www.testsite.org/?username=dustin";
	   urls[3] = "http://www.google.com/api/user";
	   urls[4] = "google.com";
	   urls[5] = "http://www.google.uk/";
	   urls[6] = "http://www.google.com:8080";
	   urls[7] = "http://www.google.com:65536";
	   urls[8] = "https://www.google.com:65535";
	   urls[9] = "http//:amazon.com";
	   urls[10] = "http://www.google.org:0";
	   urls[11] = "http://www.google.com:32";
	   urls[12] = "xtp//www.google.com";
	   urls[13] = "https://www.google.com:3332/?test=testing";
	   urls[14] = "http://www.google.com:89/nom/test/dustin/abc/";
	   
	   for (int i = 0; i < size; i++) {
		   System.out.println(urls[i] + " - " + urlVal.isValid(urls[i]));
	   }
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   
   public static void main(String [ ] args) {
	   UrlValidatorTest test = new UrlValidatorTest("test");
	   test.testManualTest();
   }
   

}
