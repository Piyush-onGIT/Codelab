import React from "react"
import AppSection from "./AppSection";
import Cards from "./CardSection";
import Footer from "./FooterSection";
import HeroSection from "./HeroSection";
import Navbar from "./Navbar";

const App = () => {
    return(
        <div>
            {/* currently it will be displayed without any design as the CSS is imported from external site */}
            {/* styles will be imported when you add the link to the css file in index.js */}
            <Navbar />
            <HeroSection />
            <AppSection />
            <Cards />
            <Footer />
        </div>
    )
}

export default App;