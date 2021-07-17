/* Webpage HTML - this is the config page*/ 

#ifndef Standard_Page_Parts_h
#define Standard_Page_Parts_h

// This needs work on the navigation...
const char Page_Header[] PROGMEM = R"rawliteral(
  <div id="header">
    <h2>%title% - <em>config</em></h2>
    <div class = "menu-buttons">
      <div class = "button ButtonClickable">
        <Button1 onclick="location.href='/home'">Home</button>
      </div>
      <div class = "button ButtonHere">
        <Button2>config</button2>
      </div>
      <div class = "button ButtonClickable">
        <button3 onclick="darkFunction()">Dark Mode</button3>
      </div>
    </div>
  </div>  <!-- HEADER -->
)rawliteral";

const char Page_Footer[] PROGMEM = R"rawliteral(
  <div id="footer">
    <div class="columns mt-10">
      <span class="label label-rounded label-blank"></span> 
      <div class="columns mt-8">
        <div class="columns mt-4">
          <div class="col-12 text-center">
            <span class="label label-rounded mr-2">%IDplaceholder%</span> 
            -
            <span class="label label-rounded label-primary ml-2">%processorplaceholder%</span>
            -
            <span class="label label-rounded mr-2">%type%</span> 
          </div>
        </div> 
        <div class="columns mt-8">
          <span class="label label-rounded label-error">%errorplaceholder%</span> 
        </div>
      </div>
    </div>
  </div>  <!-- FOOTER -->
)rawliteral";

#endif  // Standard_Page_Parts_h