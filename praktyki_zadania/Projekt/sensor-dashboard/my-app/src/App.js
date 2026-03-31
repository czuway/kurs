import { useEffect, useState } from "react";
import "./App.css";

function App() {
  const [sensorData, setSensorData] = useState({
    temp: "-",
    humidity: "-",
    pressure: "-",
    waves: "-",
  });

  const fetchData = () => {
    fetch("http://localhost:5000/data")
      .then((res) => res.json())
      .then((data) => setSensorData(data))
      .catch((err) => console.error("Błąd pobierania danych:", err));
  };

  useEffect(() => {
    fetchData();
    const interval = setInterval(fetchData, 2000);
    return () => clearInterval(interval);
  }, []);

  return (
    <div className="App">
      {/* Przezroczysty navbar */}
      <nav className="navbar">
        <div className="logo">Shorebreakers</div>
        <ul className="nav-links">
          <li className="dropdown">
            <span 
              onClick={() => {
                document.getElementById('cameras')?.scrollIntoView({
                  behavior: 'smooth',
                  block: 'start'
                });
              }}
              style={{ cursor: 'pointer' }}
            >
              Kamery
            </span>
            <ul className="dropdown-menu">
              <li>Chałupy</li>
              <li>Kuźnica</li>
              <li>Jastarnia</li>
              <li>Władysławowo</li>
            </ul>
          </li>
          <li className="dropdown">
            Mapy
            <ul className="dropdown-menu">
              <li>Spoty w Polsce</li>
              <li>Wykresy</li>
              <li>Sezon surfingowy</li>
            </ul>
          </li>
          <li className="dropdown">
            Nauka
            <ul className="dropdown-menu">
              <li>Etyka surfingu</li>
              <li>Zasady na wodzie</li>
              <li>Poradniki</li>
            </ul>
          </li>
          <li className="dropdown">
            Historia
            <ul className="dropdown-menu">
              <li>Blog</li>
            </ul>
          </li>
          <li>O nas</li>
        </ul>
      </nav>

      {/* Hero z tlo.jpg */}
      <section className="hero">
        <div className="hero-content">
          <h1>Surf Bojka Kuźnica</h1>
          <p className="subtitle">Aktualne warunki na wodzie</p>
        </div>

        {/* Karty sensorów */}
        <div className="sensor-container">
          <div className="sensor-grid">
            <div className="sensor-card">
              <h3>Temperatura</h3>
              <p>{sensorData.temp} °C</p>
            </div>
            <div className="sensor-card">
              <h3>Wilgotność</h3>
              <p>{sensorData.humidity} %</p>
            </div>
            <div className="sensor-card">
              <h3>Ciśnienie</h3>
              <p>{sensorData.pressure} hPa</p>
            </div>
            <div className="sensor-card">
              <h3>Fale</h3>
              <p>{sensorData.waves} m</p>
            </div>
          </div>
        </div>
      </section>

      <section id="cameras" className="next-section">
        <h2>Cold Water Surfing na Bałtyku</h2>
        <div className="video-wrapper">
          <div className="video-container">
            <iframe
              src="https://www.youtube.com/embed/1Se6io3C6Ag?vq=hd1080"
              title="Cold Water Surfing"
              frameBorder="0"
              allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
              allowFullScreen
            ></iframe>
          </div>
        </div>
      </section>

            {/* Sekcja Kamer – 4 kafelki na pełną szerokość */}
      <section className="cameras-section">
        <div className="section-header">
          <h2>Kamery na żywo z polskich plaż</h2>
          <p>Aktualny obraz z spotów</p>
        </div>

        <div className="camera-grid">
          <div className="camera-card">
            <div className="camera-image" style={{backgroundImage: "url('/chalupy.jpg')"}}></div>
            <div className="camera-info">
              <h3>Chałupy</h3>
              <div className="status good">DOBRZE</div>
              <div className="details">
                <span>0.2-0.8m</span>
                <span>10kts N</span>
              </div>
            </div>
          </div>

          <div className="camera-card">
            <div className="camera-image" style={{backgroundImage: "url('/kuznica.jpg')"}}></div>
            <div className="camera-info">
              <h3>Kuźnica</h3>
              <div className="status fair">ŚREDNIO</div>
              <div className="details">
                <span>1.0-1.5m</span>
                <span>8kts NW</span>
              </div>
            </div>
          </div>

          <div className="camera-card">
            <div className="camera-image" style={{backgroundImage: "url('/wladyslawowo.jpg')"}}></div>
            <div className="camera-info">
              <h3>Władysławowo</h3>
              <div className="status poor">SŁABO</div>
              <div className="details">
                <span>0.8-1.3m</span>
                <span>12kts S</span>
              </div>
            </div>
          </div>

          <div className="camera-card">
            <div className="camera-image" style={{backgroundImage: "url('/jastarnia.jpg')"}}></div>
            <div className="camera-info">
              <h3>Jastarnia</h3>
              <div className="status good">DOBRZE</div>
              <div className="details">
                <span>0.6-1.0m</span>
                <span>6kts NW</span>
              </div>
            </div>
          </div>
        </div>
      </section>


            {/* Sekcja BLOG – duże karty */}
      <section className="blog-section">
        <div className="blog-header">
          <div>
            <h2>BLOG</h2>
            <p>Ostatnie informacje ze świata</p>
          </div>
          <button className="view-all-btn">View all →</button>
        </div>

        <div className="blog-grid">
          {/* Karta 1 */}
          <div className="blog-card">
            <div className="blog-image" style={{backgroundImage: "url('/blog1.jpg')"}}></div>
            <div className="blog-content">
              <h3>Surfing w Polsce zimą</h3>
              <div className="blog-tag">Nowości</div>
            </div>
          </div>

          {/* Karta 2 */}
          <div className="blog-card">
            <div className="blog-image" style={{backgroundImage: "url('/blog2.jpg')"}}></div>
            <div className="blog-content">
              <h3>Końcówka zimowego sezonu w Maroko</h3>
              <div className="blog-tag">Ważne</div>
            </div>
          </div>

          {/* Karta 3 */}
          <div className="blog-card">
            <div className="blog-image" style={{backgroundImage: "url('/huragan.jpg')"}}></div>
            <div className="blog-content">
              <h3>Śledzenie huraganów przechodzi poważną modernizację na rok 2026</h3>
              <div className="blog-tag">Pogoda</div>
            </div>
          </div>
        </div>
      </section>

            {/* FOOTER */}
      <footer className="footer">
        <div className="footer-content">
          {/* Lewa kolumna - Logo + info */}
          <div className="footer-left">
            <div className="footer-logo">Shorebreakers</div>
            <p>© 2026 Shorebreakers. Wszystkie prawa zastrzeżone.</p>
            <p>Terms of Use &amp; Privacy Policy</p>
          </div>

          {/* Kolumna Company */}
          <div className="footer-column">
            <h4>Company</h4>
            <ul>
              <li>O nas</li>
              <li>Blog</li>
              <li>Kariera</li>
              <li>Kontakt</li>
            </ul>
          </div>

          {/* Kolumna Support */}
          <div className="footer-column">
            <h4>Support</h4>
            <ul>
              <li>Centrum pomocy</li>
              <li>Moje konto</li>
              <li>Zgłoś problem</li>
              <li>FAQ</li>
            </ul>
          </div>

          {/* Kolumna Partners */}
          <div className="footer-column">
            <h4>Partners</h4>
            <div className="partners-logos">
              <span>WSL</span>
              <span>VANS</span>
              <span>Quiksilver</span>
              <span>Roxy</span>
            </div>
          </div>

          {/* Social Media */}
          <div className="footer-social">
            <h4>Śledź nas</h4>
            <div className="social-icons">
              <a href="#" aria-label="Facebook">FB</a>
              <a href="#" aria-label="Instagram">IG</a>
              <a href="#" aria-label="YouTube">YT</a>
              <a href="#" aria-label="X">𝕏</a>
              <a href="#" aria-label="TikTok">TT</a>
            </div>
          </div>
        </div>

        <div className="footer-bottom">
          Monitoring surferski polskiego wybrzeża
        </div>
      </footer>
    </div>

    
  );
}

export default App;