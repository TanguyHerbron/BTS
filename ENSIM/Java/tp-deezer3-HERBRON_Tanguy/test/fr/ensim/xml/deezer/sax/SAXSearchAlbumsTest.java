package fr.ensim.xml.deezer.sax;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;
import org.junit.Test;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

/**
 * @author Denis Apparicio
 * 
 */
public class SAXSearchAlbumsTest {
  static {
    DOMConfigurator.configure("log4J.xml");
  }

  private static final Logger LOG = Logger.getLogger(SAXSearchAlbumsTest.class);
 
  @Test
  public void testParse() throws ParserConfigurationException, SAXException, IOException {
    LOG.debug(">>testParse");

    // Recuperation du flux a parser
    InputStream in = getClass().getResourceAsStream("../list-albums.xml");
    
    SAXParserFactory factory = SAXParserFactory.newInstance();
    factory.setNamespaceAware(true);
    SAXParser parser = factory.newSAXParser();

    // constitution du flux xml
    BufferedReader reader = new BufferedReader(new InputStreamReader(in));
    InputSource source = new InputSource(reader);

    // parsing
    SAXSearchAlbumsHandler handler = new SAXSearchAlbumsHandler();
    parser.parse(source, handler);
    
    assertEquals(10, handler.getListAlbum().size());
    //First album
    assertEquals("47685332", handler.getListAlbum().get(0).getId());
    assertEquals("The Evol", handler.getListAlbum().get(0).getTitle());
    assertEquals("http://api.deezer.com/2.0/album/47685332/image", handler.getListAlbum().get(0).getCover());
    assertEquals("83325", handler.getListAlbum().get(0).getArtist().getId());
    assertEquals("Shaka Ponk", handler.getListAlbum().get(0).getArtist().getName());

    //Second album
    assertEquals("1121440", handler.getListAlbum().get(1).getId());
    assertEquals("The Geeks And The Jerkin' Socks", handler.getListAlbum().get(1).getTitle());
    assertEquals("http://api.deezer.com/2.0/album/1121440/image", handler.getListAlbum().get(1).getCover());
    assertEquals("83325", handler.getListAlbum().get(1).getArtist().getId());
    assertEquals("Shaka Ponk", handler.getListAlbum().get(1).getArtist().getName());
    
    LOG.debug("<<testParse");
  }

}
